package app.models;

import javax.servlet.http.HttpServletRequest;

public class Task
{
    final public static String[] FIELDS = new String[] {
      "title",
      "description",
      "date",
      "priority"
    };

    final public int MIN_PRIORITY = 1;
    final public int MIDDLE_PRIORITY = 2;
    final public int MAX_PRIORITY = 3;

    // Новая задача
    final public int STATUS_NEW = 1;

    // Задача выполнена
    final public int STATUS_COMPLETED = 2;

    public int id;

    /**
     * Название
     */
    public String title;

    /**
     * Описание
     */
    public String description;

    /**
     * Дата
     */
    public String date;

    /**
     * Приоритет
     */
    private int priority;

    /**
     * Статус
     */
    private int status;

    public Task()
    {
        status = STATUS_NEW;
    }

    /**
     * Получить приоритет
     */
    public int getPriority()
    {
        return priority;
    }

    /**
     * Установить приоритет
     */
    public void setPriority(int newPriority)
    {
        if (newPriority < MIN_PRIORITY) {
            newPriority = MIN_PRIORITY;
        } else if (newPriority > MAX_PRIORITY) {
            newPriority = MAX_PRIORITY;
        }

        priority = newPriority;
    }

    /**
     * Установить статус
     */
    public void setStatus(int newStatus)
    {
        if (newStatus > STATUS_COMPLETED) {
            newStatus = STATUS_COMPLETED;
        } else if (newStatus < STATUS_NEW) {
            newStatus = STATUS_NEW;
        }

        status = newStatus;
    }

    /**
     * Имеет ли задача comparedStatus статус
     */
    public boolean hasStatus(int comparedStatus)
    {
        return status == comparedStatus;
    }

    /**
     * Установить статус "выполнена"
     */
    public Task perform()
    {
        setStatus(STATUS_COMPLETED);

        return this;
    }

    /**
     * Получить приоритет текстом
     */
    public String getPriorityText()
    {
        if (priority == MAX_PRIORITY) {
            return "высокий";
        }

        if (priority == MIDDLE_PRIORITY) {
            return "средний";
        }

        return "низкий";
    }

    /**
     * Получить цвет приоритета
     */
    public String getPriorityColor()
    {
        if (priority == MAX_PRIORITY) {
            return "success";
        }

        if (priority == MIDDLE_PRIORITY) {
            return "warning";
        }

        return "danger";
    }

    /**
     * Имеет ли задача comparedPriority приоритет
     */
    public boolean hasPriority(int comparedPriority)
    {
        return priority == comparedPriority;
    }

    /**
     * Получить статус
     */
    public int getStatus()
    {
        return status;
    }

    /**
     * Получить статус текстом
     */
    public String getStatusText()
    {
        if (status == STATUS_COMPLETED) {
            return "выполнена";
        }

        return "создана";
    }

    /**
     * Получить цвет статуса
     */
    public String getStatusColor()
    {
        if (status == STATUS_COMPLETED) {
            return "success";
        }

        return "warning";
    }

    /**
     * Заполнить задачу данными из запроса
     */
    public Task fill(HttpServletRequest request)
    {
        title = request.getParameter("title");
        description = request.getParameter("description");
        date = request.getParameter("date");
        setPriority(Integer.parseInt(request.getParameter("priority")));

        return this;
    }
}
