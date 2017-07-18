package br.com.armancocouto;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.boot.ApplicationRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;
import php.java.bridge.http.JavaBridgeRunner;

@SpringBootApplication
public class Application {

  private static final Logger logger = LoggerFactory.getLogger(Application.class);

  public static void main(String[] args) {
    SpringApplication.run(Application.class, args);
  }

  @Bean(destroyMethod = "destroy")
  protected JavaBridgeRunner javaBridgeRunner() {
    return JavaBridgeRunner.getInstance("8080");
  }

  @Bean
  protected ApplicationRunner applicationRunner(JavaBridgeRunner javaBridgeRunner) {
    return args -> (new Thread(() -> {
      try {
        javaBridgeRunner.waitFor();
      } catch (InterruptedException ex) {
        logger.error("Servidor PHPJavaBridge foi interrompido!", ex);
      }
    })).start();
  }
}
