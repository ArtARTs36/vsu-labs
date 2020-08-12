<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="app.models.Task" %>
<%
    ServletContext sc = request.getServletContext();
    Task task = (Task) sc.getAttribute("task");
%>

<div class="widget-content p-0">
    <div class="widget-content-wrapper">
        <div style="width:100%">
            <div class="task-field">
                Название: <%= task.title%>
            </div>

            <div class="task-field">
                Описание <%= task.description %>
            </div>

            <div class="task-field">
                Приоритет:
                <span class="badge badge-<%= task.getPriorityColor()%> ml-2">
                        <%= task.getPriorityText() %>
                </span>
            </div>

            <div class="task-field">
                Статус:
                <span class="badge badge-<%= task.getStatusColor()%> ml-2">
                        <%= task.getStatusText() %>
                </span>
            </div>

            <div class="task-field">
                Дата: <%= task.date %>
            </div>
        </div>
    </div>
</div>