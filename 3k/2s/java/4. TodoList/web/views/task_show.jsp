<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<%@ page import="app.models.Task" %>
<%@ page import="app.models.Task" %>

<%
    ServletContext sc = request.getServletContext();
    Task task = (Task) sc.getAttribute("task");

    sc.setAttribute("pageTitle", "Задача #" + task.id);
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
                    Задача #<%= task.id%>

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
            <div class="scroll-area-sm">
                <perfect-scrollbar class="ps-show-limits">
                    <div style="position: static;" class="ps ps--active-y">
                        <div class="ps-content">
                            <ul class=" list-group list-group-flush">
                                <jsp:include page="task_show_item.jsp"></jsp:include>
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
