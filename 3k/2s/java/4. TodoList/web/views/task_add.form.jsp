<%@ page import="app.models.Task" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<div class="widget-content p-0">
    <form method="POST">
        <div class="form-group">
            <label for="formName">Название</label>
            <input type="text" class="form-control" id="formName" name="title"
                   value="<%= task.title != null ? task.title : "" %>">
        </div>

        <div class="form-group">
            <label for="formDescription">Описание:</label>
            <textarea id="formDescription" name="description" class="form-control" rows="2"><%= task.description != null ? task.description : "" %></textarea>
        </div>

        <div class="form-group">
            <label for="formPriority">Приоритет:</label>
            <select class="form-control" id="formPriority" name="priority">
                <option value="1"<%= task.hasPriority(1) ? " selected" : "" %>>Низкий</option>
                <option value="2"<%= task.hasPriority(2) ? " selected" : "" %>>Средний</option>
                <option value="3"<%= task.hasPriority(3) ? " selected" : "" %>>Высокий</option>
            </select>
        </div>

        <div class="form-group">
            <label for="formDate">Дата</label>
            <input type="text" id="formDate" name="date" class="form-control"
                value="<%= task.date != null ? task.date : "" %>">
        </div>
    </form>

    <script>
        $( function() {
            $( "#formDate" ).datepicker();
        } );
    </script>
</div>
