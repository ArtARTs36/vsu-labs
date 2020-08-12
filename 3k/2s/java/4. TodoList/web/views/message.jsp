<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<%
    ServletContext sc = request.getServletContext();
    String title = (String) sc.getAttribute("title");
    String message = (String) sc.getAttribute("message");
    String color = (String) sc.getAttribute("color");

    sc.setAttribute("pageTitle", "Результат");
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
                    <%= title %>
                </div>
            </div>
            <div class="scroll-area-sm">
                <perfect-scrollbar class="ps-show-limits">
                    <div style="position: static;" class="ps ps--active-y">
                        <div class="ps-content" style="padding:15px">
                            <ul class=" list-group list-group-flush">
                                <div class="alert alert-<%= color %>" role="alert">
                                    <%= message %>
                                </div>
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
