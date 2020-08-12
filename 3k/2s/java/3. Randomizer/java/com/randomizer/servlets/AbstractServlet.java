package com.randomizer.servlets;

import com.randomizer.beans.AppDetailBean;

import javax.inject.Inject;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

public class AbstractServlet extends HttpServlet
{
    @Inject
    private AppDetailBean appDetailBean;

    protected void render(HttpServletRequest request, HttpServletResponse response, String template)
    {
        request.setAttribute("appDetail", appDetailBean);

        RequestDispatcher requestDispatcher = request.getRequestDispatcher("/views/" + template + ".jsp");

        try {
            requestDispatcher.forward(request, response);
        } catch (ServletException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
