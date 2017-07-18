package br.com.armancocouto;

import java.io.Closeable;

import org.eclipse.birt.core.exception.BirtException;
import org.eclipse.birt.core.framework.Platform;
import org.eclipse.birt.report.engine.api.EngineConfig;
import org.eclipse.birt.report.engine.api.IReportEngine;
import org.eclipse.birt.report.engine.api.IReportEngineFactory;
import org.eclipse.core.internal.registry.RegistryProviderFactory;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class BirtEngine {

  private static final Logger logger = LoggerFactory.getLogger(Application.class);

  private static IReportEngine engine;

  public static IReportEngine getBirtEngine() {
    if (engine != null) {
      return engine;
    }

    EngineConfig ec = new EngineConfig();
    try {
      Platform.startup(ec);

      IReportEngineFactory ref = (IReportEngineFactory) Platform.createFactoryObject(IReportEngineFactory.EXTENSION_REPORT_ENGINE_FACTORY);

      return engine = ref.createReportEngine(ec);
    } catch (BirtException ex) {
      logger.error("Erro ao iniciar a engine!", ex);
      return null;
    }
  }

  public static Closeable getCloseable() {
    return () -> {
      engine.destroy();
      Platform.shutdown();
      RegistryProviderFactory.releaseDefault();
    };
  }
}
