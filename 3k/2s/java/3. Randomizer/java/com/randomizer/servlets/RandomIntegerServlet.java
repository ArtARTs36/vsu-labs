package com.randomizer.servlets;

import com.randomizer.support.Randomizer;

import javax.inject.Inject;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = "/random/integer")
public class RandomIntegerServlet extends AbstractServlet
{
    @Inject
    private Randomizer randomizer;

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
    {
        request.setAttribute("result", String.valueOf(randomizer.integer()));

        render(request, response, "random.result");
    }
}
