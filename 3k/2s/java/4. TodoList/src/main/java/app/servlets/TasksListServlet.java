package app.servlets;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class TasksListServlet extends AbstractTaskServlet
{
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
    {
        controller(req, resp).index();
    }
}
