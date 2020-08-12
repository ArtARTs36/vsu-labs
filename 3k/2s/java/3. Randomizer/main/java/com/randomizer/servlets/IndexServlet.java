package com.randomizer.servlets;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = "/")
public class IndexServlet extends AbstractServlet
{
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
    {
        render(request, response, "index");
    }
}
