<?php

require_once("http://localhost:8080/JavaBridge/java/Java.inc");

class ReportDesign {
    private $java;
    public function ReportDesign($java) {
        $this->java = $java;
    }
    public function getJava() {
       return $this->java;
    }
}

class ReportDocument {
    private $java;
    public function ReportDocument($java) {
        $this->java = $java;
    }
    public function close() {
       $this->java->close();
    }
    public function getJava() {
       return $this->java;
    }
}

class RunTask {
    private $java;
    public function RunTask($java) {
        $this->java = $java;
    }
    public function run($reportDocument) {
       $this->java->run($reportDocument);
    }
    public function close() {
       $this->java->close();
    }
    public function getJava() {
       return $this->java;
    }
}

class RenderTask {
    private $java;
    public function RenderTask($java) {
        $this->java = $java;
    }
    public function setRenderOption(RenderOption $options) {
        $this->java->setRenderOption($options->getJava());
    }
    public function setPageRange($pageRange) {
        $this->java->setPageRange($pageRange);
    }
    public function render() {
        $this->java->render();
    }
    public function close() {
       $this->java->close();
    }
    public function getJava() {
       return $this->java;
    }
}

class BirtEngine {
    private $java;
    private function BirtEngine($java) {
        $this->java = $java;
    }
    /**
     * @return BirtEngine
     */
    public static function getBirtEngine() {
        $java = java("br.com.armandocouto.BirtEngine")->getBirtEngine();
        java_context()->onShutdown(java("br.com.armandocouto.BirtEngine")->getCloseable());
        return new BirtEngine($java);
    }
    /**
     * @param string $reportDesign
     * @return ReportDesign
     */
    public function openReportDesign($reportDesign) {
        return new ReportDesign($this->java->openReportDesign($reportDesign));
    }/**
     * @param string $reportDocument
     * @return ReportDocument
     */
    public function openReportDocument($reportDocument) {
        return new ReportDocument($this->java->openReportDocument($reportDocument));
    }
    /**
     * @param ReportDesign $report
     * @return RunTask
     */
    public function createRunTask(ReportDesign $report) {
        return new RunTask($this->java->createRunTask($report->getJava()));
    }
    /**
     * @param ReportDocument $report
     * @return RenderTask
     */
    public function createRenderTask(ReportDocument $report) {
        return new RenderTask($this->java->createRenderTask($report->getJava()));
    }
    public function getJava() {
       return $this->java;
    }
}

class ByteArrayOutputStream {
    private $java;
    public function ByteArrayOutputStream() {
        $this->java = new java("java.io.ByteArrayOutputStream");
    }
    public function getJava() {
       return $this->java;
    }
    public function toByteArray() {
        return $this->java->toByteArray();
    }
}

class HTMLServerImageHandler {
    private $java;
    public function HTMLServerImageHandler() {
        $this->java = new java("org.eclipse.birt.report.engine.api.HTMLServerImageHandler");
    }
    public function getJava() {
       return $this->java;
    }
}

class RenderOption {
    private $java;
    public function RenderOption() {
        $this->java = new java("org.eclipse.birt.report.engine.api.RenderOption");
    }
    public function setOutputFormat($outputFormat) {
        $this->java->setOutputFormat($outputFormat);
    }
    public function setOutputStream(ByteArrayOutputStream $outputStream) {
        $this->java->setOutputStream($outputStream->getJava());
    }
    public function getJava() {
       return $this->java;
    }
}

class HTMLRenderOption {
    private $java;
    public function HTMLRenderOption(RenderOption $renderOption = null) {
        if (is_null($renderOption)) {
            $this->java = new java("org.eclipse.birt.report.engine.api.HTMLRenderOption");
        } else {
            $this->java = new java("org.eclipse.birt.report.engine.api.HTMLRenderOption", $renderOption->getJava());
        }
    }
    public function setImageHandler(HTMLServerImageHandler $imageHandler) {
        $this->java->setImageHandler($imageHandler->getJava());
    }
    public function setImageDirectory($imageDirectory) {
        $this->java->setImageDirectory($imageDirectory);
    }
    public function setBaseImageURL($baseImageURL) {
        $this->java->setBaseImageURL($baseImageURL);
    }
    public function setHtmlPagination($htmlPagination) {
        $this->java->setHtmlPagination($htmlPagination);
    }
    public function setHtmlRtLFlag($htmlRtLFlag) {
        $this->java->setHtmlRtLFlag($htmlRtLFlag);
    }
    public function setEmbeddable($embeddable) {
        $this->java->setEmbeddable($embeddable);
    }
    public function getJava() {
       return $this->java;
    }
}

class PDFRenderOption {
    private $java;
    public function PDFRenderOption(RenderOption $renderOption = null) {
        if (is_null($renderOption)) {
            $this->java = new java("org.eclipse.birt.report.engine.api.PDFRenderOption");
        } else {
            $this->java = new java("org.eclipse.birt.report.engine.api.PDFRenderOption", $renderOption->getJava());
        }
    }
    public function getJava() {
       return $this->java;
    }
}