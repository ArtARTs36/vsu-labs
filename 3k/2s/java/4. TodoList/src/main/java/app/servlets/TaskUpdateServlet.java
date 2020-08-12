package app.servlets;

import app.models.Task;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class TaskUpdateServlet extends AbstractTaskServlet
{
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
    {
        Task task = getTask(req);

        if (task == null) {
            controller(req, resp).notFound();
        } else {
            controller(req, resp).edit(task);
        }
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
    {
        if (isTaskValidate(req)) {
            controller(req, resp).update(getTask(req));
        } else {
            controller(req, resp).error(
                    "Не удалось обновить задачу",
                    "Проверьте корректность введенных данных"
            );
        }
    }
}
