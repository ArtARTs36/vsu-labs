package app.controllers;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

abstract public class BaseController
{
    protected static TaskController instance = null;

    protected static HttpServletRequest request;

    protected static HttpServletResponse response;

    protected static ServletContext context;

    protected void render(String template)
    {
        RequestDispatcher requestDispatcher = request.getRequestDispatcher("/views/" + template + ".jsp");

        try {
            requestDispatcher.forward(request, response);
        } catch (ServletException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static TaskController getInstance(
            HttpServletRequest newRequest,
            HttpServletResponse newResponse,
            ServletContext newContext
    )
    {
        request = newRequest;
        response = newResponse;
        context = newContext;

        if (instance == null) {
            instance = new TaskController();
        }

        return instance;
    }

    /**
     * Вывод сообщения об ошибке
     */
    public void error(String title, String message)
    {
        message("Ошибка: " + title, message, "danger");
    }

    /**
     * Вывод сообщения о успешном действии
     */
    protected void success(String title, String message)
    {
        message(title, message, "success");
    }

    /**
     * Вывод сообщения
     */
    protected void message(String title, String message, String color)
    {
        context.setAttribute("title", title);
        context.setAttribute("message", message);
        context.setAttribute("color", color);

        render("message");
    }
}
