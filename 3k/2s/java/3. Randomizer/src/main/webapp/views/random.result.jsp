<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<html>
<%@ include file="base.head.jsp" %>
<body>

<div class="container">
    <div class="row">
        <div class="creditCardForm">
            <div class="heading">
                <h1><%= request.getAttribute("result") %></h1>
            </div>

            <%@ include file="base.buttons.jsp" %>
            <%@ include file="base.foot.jsp" %>
        </div>
    </div>
</div>

</body>
</html>
