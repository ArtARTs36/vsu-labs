<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<div class="d-block text-right card-footer">
    <button class="mr-2 btn btn-link btn-sm" onclick="redirect('${pageContext.request.contextPath}')">
        К списку
    </button>

    <button class="btn btn-primary" onclick="redirect('${pageContext.request.contextPath}/tasks/add')">
        Добавить задачу
    </button>
</div>
