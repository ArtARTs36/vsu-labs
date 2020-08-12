<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<%@ page import="app.models.Task" %>
<%@ page import="java.util.ArrayList" %>

<%
    ServletContext sc = request.getServletContext();

    sc.setAttribute("pageTitle", "Список задач");
%>

<html>
<%@ include file="base.head.jsp" %>
<body>

<div class="row d-flex justify-content-center container">
    <div class="col-md-8">
        <div class="card-hover-shadow-2x mb-3 card">
            <div class="card-header-tab card-header">
                <div class="card-header-title font-size-lg text-capitalize font-weight-normal">
                    <i class="fa fa-tasks"></i>&nbsp;
                    Список задач (${tasks_count})
                </div>
            </div>
            <div class="scroll-area-sm">
                <perfect-scrollbar class="ps-show-limits">
                    <div style="position: static;" class="ps ps--active-y">
                        <div class="ps-content">
                            <ul class=" list-group list-group-flush">
                                    <%
                                        ArrayList<Task> tasks = (ArrayList<Task>) sc.getAttribute("tasks");

                                        if (tasks.size() > 0) {
                                        for (Task task: tasks) {
                                            sc.setAttribute("currentTask", task);
                                    %>
                                        <jsp:include page="tasks_item.jsp"></jsp:include>
                                    <% }} else { %>
                                        <jsp:include page="tasks_not_created.jsp"></jsp:include>
                                    <% }%>
                            </ul>
                        </div>
                    </div>
                </perfect-scrollbar>
            </div>
            <%@ include file="base.foot.buttons.jsp" %>
        </div>
    </div>
</div>

</body>
</html>
