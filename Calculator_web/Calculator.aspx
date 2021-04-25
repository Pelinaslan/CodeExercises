<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Calculator.aspx.cs" Inherits="HesapMakinesi.Calculator" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>Hesap Makinesi</title>
</head>
<body>
    <form id="form1" runat="server">
        <div >
            <p>
            <asp:TextBox ID="TextBox" runat="server" Width="204px" Height="40px"  Font-Bold="true" Font-Size="20px" BorderColor="Black" AutoPostBack="True"></asp:TextBox>
            <br/>
            </p>

            <p>
            <asp:Button ID="Button1" Height="60px" Width="50px" Font-Size="Large" Text-size="100px" runat="server" BorderColor="Blue" Text="7" OnClick="Button1_Click" /> 
            <asp:Button ID="Button2"  Height="60px" Width="50px" Font-Size="Large" runat="server" BorderColor="Blue" Text="8" OnClick="Button2_Click" /> 
            <asp:Button ID="Button3"  Height="60px" Width="50px" Font-Size="Large" runat="server" BorderColor="Blue" Text="9" OnClick="Button3_Click" />             
            <asp:Button ID="Button4"  Height="60px" Width="50px" Font-Size="Large" runat="server" BorderColor="Blue" Text="/" OnClick="Button4_Click" />
            <br/>            
            </p>

            <p>
            <asp:Button ID="Button5" Height="60px" Width="50px" Font-Size="Large" runat="server" BorderColor="Blue" Text="4" OnClick="Button5_Click" /> 
            <asp:Button ID="Button6"  Height="60px" Width="50px" Font-Size="Large" runat="server" BorderColor="Blue" Text="5" OnClick="Button6_Click" /> 
            <asp:Button ID="Button7"  Height="60px" Width="50px" Font-Size="Large" runat="server" BorderColor="Blue" Text="6" OnClick="Button7_Click" /> 
            <asp:Button ID="Button8"  Height="60px" Width="50px" Font-Size="Large" runat="server" BorderColor="Blue" Text="*" OnClick="Button8_Click" />
            <br/>
            </p>

            <p>
            <asp:Button ID="Button9" Height="60px" Width="50px" Font-Size="Large" runat="server" BorderColor="Blue" Text="1" OnClick="Button9_Click" /> 
            <asp:Button ID="Button10"  Height="60px" Width="50px" Font-Size="Large" runat="server" BorderColor="Blue" Text="2" OnClick="Button10_Click" /> 
            <asp:Button ID="Button11"  Height="60px" Width="50px" Font-Size="Large" runat="server" BorderColor="Blue" Text="3" OnClick="Button11_Click" /> 
            <asp:Button ID="Button12"  Height="60px" Width="50px" Font-Size="Large" runat="server" BorderColor="Blue" Text="-" OnClick="Button12_Click" />
            <br/>
            </p>

            <p>
            <asp:Button ID="Button13" Height="60px" Width="50px" Font-Size="Large" runat="server" BorderColor="Blue" Text="0" OnClick="Button13_Click" /> 
            <asp:Button ID="Button14"  Height="60px" Width="50px" Font-Size="Large" runat="server" BorderColor="Blue" Text="+" OnClick="Button14_Click" /> 
            <asp:Button ID="Button15" Height="60px" Width="50px" Font-Size="Large" runat="server" BorderColor="Blue" Text="CLC" OnClick="Button15_Click" /> 
            <asp:Button ID="Button16"  Height="60px" Width="50px" Font-Size="Large" runat="server" BorderColor="Blue" Text="=" OnClick="Button16_Click" />
            </p>
        </div>
    </form>
</body>
</html>