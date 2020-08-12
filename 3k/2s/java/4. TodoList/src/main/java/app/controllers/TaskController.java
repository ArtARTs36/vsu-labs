package app.controllers;

import app.models.Task;
import app.repositories.TaskRepository;

public class TaskController extends BaseController
{
    /**
     * Отобразить все задачи
     */
    public void index()
    {
        context.setAttribute("tasks", TaskRepository.all());
        context.setAttribute("tasks_count", TaskRepository.count());

        render("tasks_list");
    }

    /**
     * Отобразить форму для создания задачи
     */
    public void create()
    {
        render("tasks_add");
    }

    /**
     * Отобразить форму для редактирования задачи
     */
    public void edit(Task task)
    {
        context.setAttribute("task", task);
        render("task_edit");
    }

    public void update(Task task)
    {
        TaskRepository.update(task.fill(request));

        success("Задача обновлена", "Задача обновлена");
    }

    /**
     * Создать задачу
     */
    public void store()
    {
        Task task = new Task();

        TaskRepository.push(task.fill(request));

        context.setAttribute("taskTitle", task.title);

        success("Задача добавлена", "Задача \"" + task.title + "\" добавлена");
    }

    /**
     * Отобразить задачу
     */
    public void show(Task task)
    {
        context.setAttribute("task", task);

        render("task_show");
    }

    /**
     * Удалить задачу
     */
    public void destroy(Task task)
    {
        TaskRepository.delete(task);

        success("Задача удалена", "Задача \"" + task.title + "\" удалена");
    }

    /**
     * Перевести задачу в статус "выполнена"
     */
    public void perform(Task task)
    {
        TaskRepository.update(task.perform());

        success("Задача выполнена", "Задаче \"" + task.title + "\" установлен статус 'Выполнена'");
    }

    /**
     * Заглушка при несуществовании задачи
     */
    public void notFound()
    {
        error("Задача не найдена", "Задача не существует. Проверьте корректность введенных данных");
    }
}
