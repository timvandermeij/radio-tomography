<?php
$header = 'Xstep "Node 1, channel 11" "Node 1, channel 16" "Node 1, channel 21" "Node 1, channel 26" "Node 2, channel 11" "Node 2, channel 16" "Node 2, channel 21" "Node 2, channel 26"';

$distances = array(
    "18 cm",
    "36 cm",
    "72 cm",
    "108 cm",
    "180 cm",
    "252 cm"
);

$output = $header . PHP_EOL;
$files = array(1, 2, 3, 4, 5, 6);

foreach($files as $k => $i) {
    $input = file_get_contents($i . ".txt");
    $lineArray = explode("\n", $input);
    $data = array();

    foreach($lineArray as $line) {
        if($line != "") {
            $line = str_replace("(", "", $line);
            $line = str_replace(")", "", $line);
            $values = explode(", ", $line);
            $nodeId = $values[1];
            $rssiNode1 = $values[2];
            $rssiNode2 = $values[3];
            $channel = $values[4];
            $data[$nodeId][$channel][] = ($nodeId == 1 ? $rssiNode2 : $rssiNode1);
        }
    }

    $averages = array();
    $count = 0;
    $number = 0;

    $node1channel11average = 0;
    foreach($data as $node => $channels) {
        $count = $number = 0;
        foreach($channels as $channel => $values) {
            foreach($values as $value) {
                $count++;
                $number += $value;
            }
            $averages[$node][$channel] = ($number / $count);
        }
    }

    $output .= "\"" . $distances[$k] . "\" " . $averages[1][11] . " " . $averages[1][16] . " " . $averages[1][21] . " " . $averages[1][26] . 
               " " . $averages[2][11] . " " . $averages[2][16] . " " . $averages[2][21] . " " . $averages[2][26] . PHP_EOL;
}
file_put_contents("antenna-upwards.dat", $output);
?>
