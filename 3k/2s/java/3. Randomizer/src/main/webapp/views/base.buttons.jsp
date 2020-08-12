<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<%
    String currentPath = pageContext.getRequest().getServletContext().getContextPath();
%>

<div class="payment">
    <div class="form-group">
        <button type="submit" class="btn btn-default"
                onclick="window.location.href ='<%= currentPath %>/random/integer'">
            Случайное число
        </button>

        <button type="submit" class="btn btn-default"
                onclick="window.location.href ='<%= currentPath %>/random/name'">
            Случайное имя
        </button>

        <button type="submit" class="btn btn-default"
                onclick="window.location.href ='<%= currentPath %>/random/family'">
            Случайная фамилия
        </button>
    </div>
</div>