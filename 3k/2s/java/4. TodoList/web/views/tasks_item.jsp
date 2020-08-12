<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="app.models.Task" %>
<%
    ServletContext sc = request.getServletContext();
    Task task = (Task) sc.getAttribute("currentTask");
%>

<li class="list-group-item">
    <div class="todo-indicator bg-<%= task.getStatusColor() %>"></div>
    <div class="widget-content p-0">
        <div class="widget-content-wrapper">
            <div class="widget-content-left flex2">
                <div class="widget-heading">
                    #<%= task.id %>:
                    <%= task.title %>

                    <div class="badge badge-<%= task.getPriorityColor()%> ml-2">
                        приоритет: <%= task.getPriorityText() %>
                    </div>
                </div>

                <div class="widget-subheading"><%= task.date %></div>
            </div>

            <div class="widget-content-right">
                <button class="border-0 btn-transition btn btn-outline-gray"
                    onclick="redirect('${pageContext.request.contextPath}/tasks/<%= task.id %>')"
                >
                    <i class="fa fa-eye"></i>
                </button>

                <button class="border-0 btn-transition btn btn-outline-gray"
                    onclick="redirect('${pageContext.request.contextPath}/tasks/update/<%= task.id %>')"
                >
                    <i class="fa fa-edit"></i>
                </button>

                <button class="border-0 btn-transition btn btn-outline-success"
                    onclick="redirect('${pageContext.request.contextPath}/tasks/perform/<%= task.id %>')"
                    >
                    <i class="fa fa-check"></i>
                </button>

                <button class="border-0 btn-transition btn btn-outline-danger"
                    onclick="redirect('${pageContext.request.contextPath}/tasks/destroy/<%= task.id %>')"
                >
                    <i class="fa fa-trash"></i>
                </button>
            </div>
        </div>
    </div>
</li>
