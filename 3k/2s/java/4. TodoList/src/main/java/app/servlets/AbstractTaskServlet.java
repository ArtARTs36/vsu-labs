package app.servlets;

import app.controllers.TaskController;
import app.models.Task;
import app.repositories.TaskRepository;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class AbstractTaskServlet extends HttpServlet
{
    protected TaskController controller(HttpServletRequest req, HttpServletResponse resp)
    {
        return TaskController
                .getInstance(req, resp, getServletContext());
    }

    protected int getId(HttpServletRequest req)
    {
        String pathInfo = req.getPathInfo();

        return Integer.parseInt(pathInfo.substring(1));
    }

    protected Task getTask(HttpServletRequest req)
    {
        return TaskRepository.find(getId(req));
    }

    /**
     * Корректный ли запрос на редактирование/создание задачи
     */
    protected boolean isTaskValidate(HttpServletRequest req)
    {
        boolean validate = true;

        for (String field: Task.FIELDS) {
            if (req.getParameter(field).isEmpty()) {
                validate = false;
            }
        }

        return validate;
    }
}
