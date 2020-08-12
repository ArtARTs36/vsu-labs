package app.repositories;

import app.models.Task;

import java.util.ArrayList;

public class TaskRepository
{
    private static ArrayList <Task> tasks = new ArrayList<>();

    private static int increment = 0;

    /**
     * @return Массив задач
     */
    public static ArrayList <Task> all()
    {
        return tasks;
    }

    /**
     * Добавить задачу в массив
     */
    public static void push(Task task)
    {
        task.id = ++increment;

        tasks.add(task);
    }

    /**
     * Удалить задачу
     */
    public static void delete(Task task)
    {
        tasks.remove(task);
    }

    /**
     * Удалить задачу
     */
    public static boolean delete(int id)
    {
        boolean success = false;

        int index = 0;

        for (Task task: tasks) {
            index++;

            if (task.id == id) {
                tasks.remove(index);

                success = true;
            }
        }

        return success;
    }

    /**
     * Количество задач
     */
    public static int count()
    {
        return tasks.size();
    }

    /**
     * Поиск задачи
     */
    public static Task find(int id)
    {
        for (Task task: tasks) {
            if (task.id == id) {
                return task;
            }
        }

        return null;
    }

    /**
     * Поиск индекса
     */
    public static int findIndex(Task task)
    {
        return tasks.indexOf(task);
    }

    /**
     * Обновить задачу
     */
    public static Task update(Task task)
    {
        tasks.set(findIndex(task), task);

        return task;
    }
}
