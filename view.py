from PyQt4 import QtCore,QtGui

rendering = False

import pyqtgraph as pg
pg.setConfigOptions(useWeave=False) # this makes it work where weave is broken (e.g. anaconda at Leiden)

import matplotlib
matplotlib.use('Agg')

import math
import numpy as np
import scipy as sp
import scipy.sparse
import scipy.sparse.linalg
import scipy.optimize
import scipy.ndimage
import matplotlib.pyplot as plt
cmap = plt.get_cmap('bwr')

import weights
class RadioData:
	def initWeights(self):
		self.weights = weights.createWeights(self.nodes, self.resX, self.resY, self._lambda)
		self.weights = sp.sparse.csc_matrix(self.weights)
		self.weightsT = sp.sparse.csc_matrix(self.weights.transpose())

		self.guess = np.zeros(self.weights.shape[1])
		diffm1 = np.zeros((self.guess.shape[0], self.guess.shape[0]))
		diffm2 = np.zeros((self.guess.shape[0], self.guess.shape[0]))
		diffm3 = np.zeros((self.guess.shape[0], self.guess.shape[0]))
		diffm4 = np.zeros((self.guess.shape[0], self.guess.shape[0]))
		for xi in range(self.resX):
			for yi in range(self.resY):
				ind = yi*self.resX + xi
				if xi > 0:
					# left
					diffm1[ind][yi*self.resX + xi-1] = -1
					diffm1[ind][yi*self.resX + xi] = 1
				if xi < self.resX-1:
					# right
					diffm2[ind][yi*self.resX + xi+1] = -1
					diffm2[ind][yi*self.resX + xi] = 1
				if yi > 0:
					# up
					diffm3[ind][(yi-1)*self.resX + xi] = -1
					diffm3[ind][yi*self.resX + xi] = 1
				if yi < self.resY-1:
					# down
					diffm4[ind][(yi+1)*self.resX + xi] = -1
					diffm4[ind][yi*self.resX + xi] = 1
		self.diffm1 = sp.sparse.csc_matrix(diffm1)
		self.diffm2 = sp.sparse.csc_matrix(diffm2)
		self.diffm3 = sp.sparse.csc_matrix(diffm3)
		self.diffm4 = sp.sparse.csc_matrix(diffm4)

class FileData(RadioData):
	def __init__(self):
		self.nodes = [
[0,0],
[0,3],
[0,6],
[0,9],
[0,12],
[0,15],
[0,18],
[0,21],
[3,21],
[6,21],
[9,21],
[12,21],
[15,21],
[18,21],
[21,21],
[21,18],
[21,15],
[21,12],
[21,9],
[21,6],
[21,3],
[21,0],
[18,0],
[15,0],
[12,0],
[9,0],
[6,0],
[2,0]]

		# flip the coordinates to make things work out nicely visually :)
		for i in self.nodes:
			i[1] = -i[1]

		baselines = []
		for i in self.nodes:
			bl = [0]
			for j in self.nodes:
				bl.append(0)
			baselines.append(bl)
		import csv
		f = open("data/empty.csv")
		mcsv = csv.reader(f)
		for i in mcsv:
			nodeid = int(i[0])
			bl = baselines[nodeid]
			bl[0] = bl[0] + 1
			for j in range(len(self.nodes)):
				val = int(i[j+1])
				bl[j+1] = bl[j+1] + val
		for bl in baselines:
			for j in range(len(self.nodes)):
				bl[j+1] = bl[j+1] / float(bl[0])

		f = open("data/m-2.csv")
		mcsv = csv.reader(f)
		self.states = []
		laststate = 0
		vals = []
		for i in mcsv:
			s = []
			t = 0
			for n in i:
				val = int(n)
				# first column is node id, last three columns are timestamp
				if t > 0 and t <= len(self.nodes):
					val = val - baselines[s[0]][t]
					vals.append(val)
				s.append(val)
				t = t + 1
			# ignore the first states (old data)
			if s[0] != 0 and len(self.states) == 0:
				continue
			# pad out missing data
			while s[0] != laststate:
				self.states.append(None)
				laststate = (laststate + 1) % len(self.nodes)
			self.states.append(s)
			laststate = (laststate + 1) % len(self.nodes)

		self.minstate = np.percentile(vals, 5)
		self.maxstate = np.percentile(vals, 95)

class Viewer(QtGui.QWidget):
	def __init__(self, mydata):
		QtGui.QWidget.__init__(self)
		self.data = mydata
		self.stateid = 0

		self.data._lambda = 0.01
		res = 64
		self.data.resX = res
		self.data.resY = res

		self.view = QtGui.QGraphicsView(self)
		self.view.setRenderHint(QtGui.QPainter.Antialiasing)

		self.scene = QtGui.QGraphicsScene()
		self.view.setScene(self.scene)

		if not rendering:
			self.canvas = QtGui.QLabel(self)

		self.slider = QtGui.QSlider(QtCore.Qt.Horizontal, self)
		self.slider.setTickPosition(QtGui.QSlider.TicksBothSides)
		self.slider.setTickInterval(1)
		self.slider.setMinimum(1)
		self.slider.setMaximum(len(self.data.states)/len(self.data.nodes))
		self.slider.valueChanged[int].connect(self.changeState)

		layout = QtGui.QVBoxLayout(self)
		hlayout = QtGui.QHBoxLayout(self)
		hlayout.addWidget(self.view,1)
		layout.addLayout(hlayout)
		layout.addWidget(self.slider)
		if not rendering:
			hlayout.addWidget(self.canvas,1)
		self.setLayout(layout)

		self.nodes = []
		self.links = []
		for i in range(len(self.data.nodes)):
			n = self.data.nodes[i]
			links = []
			for j in range(len(self.data.nodes)):
				if j == i:
					links.append(None)
					continue
				if j < i:
					links.append(self.links[j][i])
					continue
				o = self.data.nodes[j]
				li = self.scene.addLine(QtCore.QLineF(n[0], n[1], o[0], o[1]))
				links.append(li)
			self.links.append(links)
		for i in range(len(self.data.nodes)):
			n = self.data.nodes[i]
			si = QtGui.QGraphicsEllipseItem()
			si.nodeId = i
			si.setRect(-0.25, -0.25, 0.5, 0.5)
			si.setPos(n[0], n[1])
			self.scene.addItem(si)
			self.nodes.append(si)

		self.setMinimumSize(800, 600)

		self.data.initWeights()

		self.updateScene()

	def changeState(self, value):
		self.stateid = value - 1
		self.updateScene()

	def updateScene(self):
		for links in self.links:
			for li in links:
				if li:
					col = 220
					li.setPen(QtGui.QPen(QtGui.QColor(col, col, col)))
		count = len(self.data.nodes)
		ourlines = []
		mlevels = np.zeros(self.data.weights.shape[0])
		seenlevels = [False]*len(mlevels)
		for n in range(count):
			state = self.data.states[self.stateid*count + n]
			if not state:
				continue
			nodeid = state[0]
			links = self.links[nodeid]
			for i in range(count):
				if i == nodeid:
					continue
				li = links[i]
				level = (state[i+1]-self.data.minstate) / (1.0*self.data.maxstate-self.data.minstate)
				if level < 0.0: level = 0.0
				elif level > 1.0: level = 1.0

				if i < n:
					index = i*count + nodeid
					if seenlevels[index]:
						# average both levels
						mlevels[index] = (mlevels[index] + level) / 2.0
						col = cmap(mlevels[index])
						li.setPen(QtGui.QPen(QtGui.QColor(col[0]*255, col[1]*255, col[2]*255)))
						continue
				else:
					index = nodeid*count + i

				mlevels[index] = level
				seenlevels[index] = True
				col = cmap(level)
				li.setPen(QtGui.QPen(QtGui.QColor(col[0]*255, col[1]*255, col[2]*255)))

		W = self.data.weights
		WT = self.data.weightsT
		y = mlevels
		WTy = WT*y
		WTW = WT*W
		alpha = 0.4
		beta = 0.001
		guess = self.data.guess
		diffm1 = self.data.diffm1
		diffm2 = self.data.diffm2
		diffm3 = self.data.diffm3
		diffm4 = self.data.diffm4
		def TVnorm(x):
			img = x.reshape((self.data.resX, self.data.resY))
			vert = (diffm1*x)**2
			vert = np.sqrt(vert + beta)
			horz = (diffm3*x)**2
			horz = np.sqrt(horz + beta)
			return sum(vert) + sum(horz)
		def TVgradEntry(val1, val2):
			return (val1 - val2)/np.sqrt((val1 - val2)**2 + beta)
		def TVgrad(v):
			return v/np.sqrt(v**2 + beta)
		def TVderiv(x):
			diff1 = TVgrad(diffm1*x)
			diff2 = TVgrad(diffm2*x)
			diff3 = TVgrad(diffm3*x)
			diff4 = TVgrad(diffm4*x)
			out = diff1+diff2+diff3+diff4
			return out
		def fTV(x):
			lsqm = W*x - y
			lsqnorm = 0.5*lsqm.transpose().dot(lsqm)
			out = lsqnorm + alpha*TVnorm(x)
			return out
		def fTVderiv(x):
			lsqderiv = WTW*x - WTy
			ret = lsqderiv + alpha*TVderiv(x)
			return ret
		solution = scipy.optimize.minimize(fTV, guess, method='L-BFGS-B', jac=fTVderiv, options={'maxiter':50})
		#print solution
		solution = solution.x
		self.data.guess = solution

		sol = solution.reshape((self.data.resX, self.data.resY)).transpose()
		levels = [sol.min(), sol.max()]
		import pyqtgraph.functions
		lut = np.array([cmap(1.0 - x/256.0) for x in range(256)])*255
		buf,alpha = pg.functions.makeRGBA(sol,levels=levels,lut=lut)
		img = pg.functions.makeQImage(buf,alpha)
		self.img = img
		self.canvas.setScaledContents(True)
		self.canvas.setPixmap(QtGui.QPixmap.fromImage(img))

	def showEvent(self, e):
		self.resizeEvent(e)

	def resizeEvent(self, e):
		edge = 0.25
		self.view.fitInView(self.scene.itemsBoundingRect().adjusted(-edge, -edge, edge, edge), QtCore.Qt.KeepAspectRatio)

if __name__ == "__main__":
	import signal
	signal.signal(signal.SIGINT, signal.SIG_DFL)
	import sys
	app = QtGui.QApplication(sys.argv)
	mydata = FileData()
	window = Viewer(mydata)
	window.show()
	app.exec_()


