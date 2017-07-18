<?php

require_once("java/BirtEngine.inc");

$reportDesignName = $_SERVER["PATH_INFO"];

try {
    $birtEngine = BirtEngine::getBirtEngine();
    
    $reportDesign = $birtEngine->openReportDesign(__DIR__."/design/$reportDesignName.rptdesign");
    
    $task = $birtEngine->createRunTask($reportDesign);
    $task->run(__DIR__."/temp/docs/$reportDesignName.rptdocument");
    
    $task->close();

    echo "OK";
} catch (JavaException $e) {
    echo "<pre>$e</pre>";
}

echo "Armandoooooooooo";