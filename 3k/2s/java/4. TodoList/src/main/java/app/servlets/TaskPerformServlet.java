package app.servlets;

import app.models.Task;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class TaskPerformServlet extends AbstractTaskServlet
{
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
    {
        Task task = getTask(req);

        if (task == null) {
            controller(req, resp).notFound();
        } else {
            controller(req, resp).perform(task);
        }
    }
}
