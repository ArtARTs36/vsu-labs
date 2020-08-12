package app.servlets;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class TasksAddServlet extends AbstractTaskServlet
{
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
    {
        controller(req, resp).create();
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
    {
        if (isTaskValidate(req)) {
            controller(req, resp).store();
        } else {
            controller(req, resp).error(
                    "Не удалось добавить задачу",
                    "Проверьте корректность введенных данных"
            );
        }
    }
}
