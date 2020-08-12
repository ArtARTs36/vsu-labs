<%@ page import="com.randomizer.beans.AppDetailBean" %>

<%
    AppDetailBean appDetail = (AppDetailBean) request.getAttribute("appDetail");
%>

<br/> <br/>

<div class="payment">
    <div class="form-group" id="pay-now">
        <%= appDetail.getAppName() %>
        <%= appDetail.getVersion() %>
    </div>
</div>
