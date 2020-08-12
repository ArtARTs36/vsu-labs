<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<%
    ServletContext sc = request.getServletContext();

    sc.setAttribute("pageTitle", "Редактировать задачу");

    Task task = (Task) sc.getAttribute("task");
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
                    Редактировать задачу #<%= task.id %>
                </div>
            </div>
            <div class="scroll-area-sm">
                <perfect-scrollbar class="ps-show-limits">
                    <div style="position: static;" class="ps ps--active-y">
                        <div class="ps-content" style="padding:15px">
                            <%@ include file="task_add.form.jsp" %>
                        </div>
                    </div>
                </perfect-scrollbar>
            </div>
            <div class="d-block text-right card-footer">
                <button class="mr-2 btn btn-link btn-sm" onclick="redirect('${pageContext.request.contextPath})'">
                    К списку
                </button>

                <button class="btn btn-primary" type="submit" onclick="$('form:eq(0)').submit()">
                    Сохранить
                </button>
            </div>
        </div>
    </div>
</div>

</body>
</html>
