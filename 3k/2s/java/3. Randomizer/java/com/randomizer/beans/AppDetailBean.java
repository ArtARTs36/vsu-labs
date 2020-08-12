package com.randomizer.beans;

import java.io.Serializable;

import javax.annotation.PostConstruct;
import javax.enterprise.context.ApplicationScoped;
import javax.inject.Named;

@Named
@ApplicationScoped
public class AppDetailBean implements Serializable {

	private String appName;
	private String version;
	private Integer maxDefaultRandomInteger;

	@PostConstruct
	public void init()
	{
		appName = "Randomizer";
		version = "1.0";
		maxDefaultRandomInteger = 2000;
	}

	public String getAppName()
	{
		return appName;
	}

	public String getVersion()
	{
		return version;
	}

	public Integer getMaxDefaultRandomInteger()
	{
		return maxDefaultRandomInteger;
	}
}
