#include <stdio.h>
#include "./WorkBook.h"

int main(int argc, char** argv) {

	WorkBook::Inst().load("G:\\zData\\openxml_xlsx\\员工通讯录.xlsx");
	return 0;
}



// 1. sheet1.表单1.

/*
< ? xml version = "1.0" encoding = "UTF-8" standalone = "yes" ? >
<worksheet xmlns = "http://schemas.openxmlformats.org/spreadsheetml/2006/main" xmlns:r = "http://schemas.openxmlformats.org/officeDocument/2006/relationships" xmlns : mc = "http://schemas.openxmlformats.org/markup-compatibility/2006" mc : Ignorable = "x14ac" xmlns : x14ac = "http://schemas.microsoft.com/office/spreadsheetml/2009/9/ac"><dimension ref = "A1:D23" / >


<sheetViews><sheetView tabSelected = "1" workbookViewId = "0"><selection activeCell = "B26" sqref = "B26" / >< / sheetView>< / sheetViews>

<sheetFormatPr defaultRowHeight = "13.5" x14ac:dyDescent = "0.15" / >


<cols>
<col min = "1" max = "1" width = "10.125" customWidth = "1" / >
<col min = "2" max = "2" width = "16" customWidth = "1" / >
<col min = "3" max = "3" width = "16.125" customWidth = "1" / >
<col min = "4" max = "4" width = "23.625" customWidth = "1" / >
< / cols>
<sheetData>

<row r = "1" spans = "1:4" x14ac:dyDescent = "0.15">		<c r = "A1" s = "3" t = "s"><v>0 < / v > < / c>	<c r = "B1" s = "3" t = "s"><v>1 < / v > < / c>			<c r = "C1" s = "3" t = "s"><v>2 < / v > < / c>					<c r = "D1" s = "3" t = "s"><v>3 < / v > < / c>< / row>
<row r = "2" spans = "1:4" x14ac:dyDescent = "0.15">		<c r = "A2" s = "1" / >						<c r = "B2" s = "1" / >							<c r = "C2" s = "1" / >									<c r = "D2" s = "1" / >< / row>
<row r = "3" spans = "1:4" x14ac:dyDescent = "0.15">		<c r = "A3" s = "2" t = "s"><v>4 < / v > < / c>	<c r = "B3" s = "4"><v>186102148617 < / v > < / c>		<c r = "C3" s = "4"><v>9408722 < / v > < / c>					<c r = "D3" s = "4" t = "s"><v>5 < / v > < / c>< / row>
<row r = "4" spans = "1:4" x14ac:dyDescent = "0.15">		<c r = "A4" s = "2" t = "s"><v>6 < / v > < / c>	<c r = "B4" s = "4"><v>186114038271 < / v > < / c>		<c r = "C4" s = "4"><v>121736036 < / v > < / c>				<c r = "D4" s = "4" t = "s"><v>7 < / v > < / c>< / row>
<row r = "5" spans = "1:4" x14ac:dyDescent = "0.15">		<c r = "A5" s = "2" t = "s"><v>8 < / v > < / c>	<c r = "B5" s = "4"><v>138104912945 < / v > < / c>		<c r = "C5" s = "4"><v>174799621 < / v > < / c>				<c r = "D5" s = "4" t = "s"><v>9 < / v > < / c>< / row>
<row r = "6" spans = "1:4" x14ac:dyDescent = "0.15">		<c r = "A6" s = "2" t = "s"><v>10 < / v > < / c>	<c r = "B6" s = "4"><v>158110520175 < / v > < / c>		<c r = "C6" s = "4"><v>406384165 < / v > < / c>				<c r = "D6" s = "4" t = "s"><v>45 < / v > < / c>< / row>
<row r = "7" spans = "1:4" x14ac:dyDescent = "0.15">		<c r = "A7" s = "2" t = "s"><v>11 < / v > < / c>	<c r = "B7" s = "4"><v>158111341413 < / v > < / c>		<c r = "C7" s = "4"><v>15930277 < / v > < / c>					<c r = "D7" s = "4" t = "s"><v>38 < / v > < / c>< / row>
<row r = "8" spans = "1:4" x14ac:dyDescent = "0.15">		<c r = "A8" s = "2" t = "s"><v>12 < / v > < / c>	<c r = "B8" s = "4"><v>137161285129 < / v > < / c>		<c r = "C8" s = "4"><v>190917775 < / v > < / c>				<c r = "D8" s = "4" t = "s"><v>32 < / v > < / c>< / row>
<row r = "9" spans = "1:4" x14ac:dyDescent = "0.15">		<c r = "A9" s = "2" t = "s"><v>13 < / v > < / c>	<c r = "B9" s = "4"><v>138111113034 < / v > < / c>		<c r = "C9" s = "4" / >									<c r = "D9" s = "4" t = "s"><v>31 < / v > < / c>< / row>
<row r = "10" spans = "1:4" x14ac:dyDescent = "0.15">		<c r = "A10" s = "2" t = "s"><v>14 < / v > < / c>	<c r = "B10" s = "4"><v>1816010576182 < / v > < / c>		<c r = "C10" s = "4"><v>1052385377 < / v > < / c>				<c r = "D10" s = "4" t = "s"><v>41 < / v > < / c>< / row>
<row r = "11" spans = "1:4" x14ac:dyDescent = "0.15">		<c r = "A11" s = "2" t = "s"><v>15 < / v > < / c>	<c r = "B11" s = "4"><v>1815111101221 < / v > < / c>		<c r = "C11" s = "4"><v>271549506 < / v > < / c>				<c r = "D11" s = "4" t = "s"><v>44 < / v > < / c>< / row>
<row r = "12" spans = "1:4" x14ac:dyDescent = "0.15">		<c r = "A12" s = "2" t = "s"><v>16 < / v > < / c>	<c r = "B12" s = "4"><v>181011037263 < / v > < / c>		<c r = "C12" s = "4"><v>10954362 < / v > < / c>				<c r = "D12" s = "4" t = "s"><v>42 < / v > < / c>< / row>
<row r = "13" spans = "1:4" x14ac:dyDescent = "0.15">		<c r = "A13" s = "2" t = "s"><v>17 < / v > < / c>	<c r = "B13" s = "4"><v>155105418556 < / v > < / c>		<c r = "C13" s = "4"><v>236069242 < / v > < / c>				<c r = "D13" s = "4" t = "s"><v>34 < / v > < / c>< / row>
<row r = "14" spans = "1:4" x14ac:dyDescent = "0.15">		<c r = "A14" s = "2" t = "s"><v>18 < / v > < / c>	<c r = "B14" s = "4"><v>1391161216367 < / v > < / c>		<c r = "C14" s = "4"><v>1382265 < / v > < / c>					<c r = "D14" s = "4" t = "s"><v>35 < / v > < / c>< / row>
<row r = "15" spans = "1:4" x14ac:dyDescent = "0.15">		<c r = "A15" s = "2" t = "s"><v>19 < / v > < / c>	<c r = "B15" s = "4"><v>1364111715448 < / v > < / c>		<c r = "C15" s = "4"><v>24436996 < / v > < / c>				<c r = "D15" s = "4" t = "s"><v>43 < / v > < / c>< / row>
<row r = "16" spans = "1:4" x14ac:dyDescent = "0.15">		<c r = "A16" s = "2" t = "s"><v>20 < / v > < / c>	<c r = "B16" s = "4"><v>1560101569291 < / v > < / c>		<c r = "C16" s = "4"><v>317133617 < / v > < / c>				<c r = "D16" s = "4" t = "s"><v>40 < / v > < / c>< / row>
<row r = "17" spans = "1:4" x14ac:dyDescent = "0.15">		<c r = "A17" s = "2" t = "s"><v>21 < / v > < / c>	<c r = "B17" s = "4"><v>1343912715589 < / v > < / c>		<c r = "C17" s = "4"><v>1161098922 < / v > < / c>				<c r = "D17" s = "4" t = "s"><v>29 < / v > < / c>< / row>
<row r = "18" spans = "1:4" x14ac:dyDescent = "0.15">		<c r = "A18" s = "2" t = "s"><v>22 < / v > < / c>	<c r = "B18" s = "4"><v>1510169111912 < / v > < / c>		<c r = "C18" s = "4"><v>304721492 < / v > < / c>				<c r = "D18" s = "4" t = "s"><v>37 < / v > < / c>< / row>
<row r = "19" spans = "1:4" x14ac:dyDescent = "0.15">		<c r = "A19" s = "2" t = "s"><v>23 < / v > < / c>	<c r = "B19" s = "4"><v>1352171614068 < / v > < / c>		<c r = "C19" s = "4"><v>369675697 < / v > < / c>				<c r = "D19" s = "4" t = "s"><v>36 < / v > < / c>< / row>
<row r = "20" spans = "1:4" x14ac:dyDescent = "0.15">		<c r = "A20" s = "2" t = "s"><v>24 < / v > < / c>	<c r = "B20" s = "4"><v>186111784447 < / v > < / c>		<c r = "C20" s = "4"><v>114208439 < / v > < / c>				<c r = "D20" s = "4" t = "s"><v>28 < / v > < / c>< / row>
<row r = "21" spans = "1:4" x14ac:dyDescent = "0.15">		<c r = "A21" s = "2" t = "s"><v>25 < / v > < / c>	<c r = "B21" s = "4"><v>1818105112750 < / v > < / c>		<c r = "C21" s = "4"><v>343950805 < / v > < / c>				<c r = "D21" s = "4" t = "s"><v>30 < / v > < / c>< / row>
<row r = "22" spans = "1:4" x14ac:dyDescent = "0.15">		<c r = "A22" s = "2" t = "s"><v>26 < / v > < / c>	<c r = "B22" s = "4"><v>1581016719125 < / v > < / c>		<c r = "C22" s = "4"><v>6905881 < / v > < / c>					<c r = "D22" s = "4" t = "s"><v>33 < / v > < / c>< / row>
<row r = "23" spans = "1:4" x14ac:dyDescent = "0.15">		<c r = "A23" s = "2" t = "s"><v>27 < / v > < / c>	<c r = "B23" s = "4"><v>186121018713 < / v > < / c>		<c r = "C23" s = "4"><v>261631267 < / v > < / c>				<c r = "D23" s = "4" t = "s"><v>39 < / v > < / c>< / row>

< / sheetData>

<phoneticPr fontId = "1" type = "noConversion" / ><pageMargins left = "0.7" right = "0.7" top = "0.75" bottom = "0.75" header = "0.3" footer = "0.3" / >
<pageSetup paperSize = "9" orientation = "portrait" r:id = "rId1" / >


< / worksheet>

*/


//////////////////////////////////////////////////////////////////////////

//shareStrings.
/*
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<sst xmlns="http://schemas.openxmlformats.org/spreadsheetml/2006/main" count="46" uniqueCount="46">

<si><t>标题</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>电视</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>电脑</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>简介</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>店名</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>liuyiqi661177</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>大全</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>keeler28</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>徐</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>aaaaaxu163</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>大全 </t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>免费</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>线</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>女孩</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>名字</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>音乐</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>体育</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>韦伟</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>动作</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>跳远</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>调高</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>阿罗</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>教程</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>语文</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>数学</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>美术</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>高手</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>消费</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>macross114208439</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>guluniu454411</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>mayikaimen</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>cloutn</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>azhou074509</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>davidliu</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>weikirby16</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>ldakico</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>ArtmanMircroMess</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>水镜</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>国石磊</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>xiaojie_2520</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>L1990yc</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>california_wz</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>bysdtd</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>xiyangyuxi</t><phoneticPr fontId="1" type="noConversion"/></si>
<si><t>chinamiwei</t></si><si><t>zhangtianhu</t><phoneticPr fontId="1" type="noConversion"/></si></sst>

*/



//////////////////////////////////////////////////////////////////////////

/*
< ? xml version = "1.0" encoding = "UTF-8" standalone = "yes" ? >
<workbook xmlns = "http://schemas.openxmlformats.org/spreadsheetml/2006/main" xmlns:r = "http://schemas.openxmlformats.org/officeDocument/2006/relationships" xmlns : mc = "http://schemas.openxmlformats.org/markup-compatibility/2006" mc : Ignorable = "x15" xmlns : x15 = "http://schemas.microsoft.com/office/spreadsheetml/2010/11/main"><fileVersion appName = "xl" lastEdited = "6" lowestEdited = "6" rupBuild = "14420" / >

<workbookPr defaultThemeVersion = "153222" / >
<mc:AlternateContent xmlns : mc = "http://schemas.openxmlformats.org/markup-compatibility/2006">
<mc:Choice Requires = "x15">
< x15ac:absPath url = "C:\Users\Administrator\Desktop\" xmlns:x15ac="http ://schemas.microsoft.com/office/spreadsheetml/2010/11/ac"/>
< / mc : Choice>
< / mc : AlternateContent><bookViews><workbookView xWindow = "0" yWindow = "0" windowWidth = "21570" windowHeight = "8175" / >
< / bookViews>
<sheets>
<sheet name = "Sheet1" sheetId = "1" r : id = "rId1" / >< / sheets>
<calcPr calcId = "152511" / >
<extLst>
	<ext uri = "{140A7094-0E35-4892-8432-C4D2E57EDEB5}" xmlns:x15 = "http://schemas.microsoft.com/office/spreadsheetml/2010/11/main">
		<x15:workbookPr chartTrackingRefBase = "1" / >
	< / ext>
< / extLst>

< / workbook>

*/


//sheetStyle
/*
< ? xml version = "1.0" encoding = "UTF-8" standalone = "yes" ? >
<styleSheet xmlns = "http://schemas.openxmlformats.org/spreadsheetml/2006/main" xmlns:mc = "http://schemas.openxmlformats.org/markup-compatibility/2006" mc : Ignorable = "x14ac" xmlns : x14ac = "http://schemas.microsoft.com/office/spreadsheetml/2009/9/ac">


<fonts count = "2" x14ac:knownFonts = "1">
	<font><sz val = "11" / ><color theme = "1" / ><name val = "宋体" / ><family val = "2" / ><charset val = "134" / ><scheme val = "minor" / >< / font>
	<font><sz val = "9" / ><name val = "宋体" / ><family val = "2" / ><charset val = "134" / ><scheme val = "minor" / >< / font>
< / fonts>

<fills count = "3">
	<fill>
		<patternFill patternType = "none" / >
	< / fill>
	<fill>
		<patternFill patternType = "gray125" / >
	< / fill>
	<fill>
		<patternFill patternType = "solid"><fgColor rgb = "FFFFC000" / ><bgColor indexed = "64" / >< / patternFill>
	< / fill>
< / fills>

<borders count = "2">
	<border><left / ><right / ><top / ><bottom / ><diagonal / >< / border>
	<border><left style = "thin"><color indexed = "64" / >< / left><right style = "thin"><color indexed = "64" / >< / right><top style = "thin"><color indexed = "64" / >< / top><bottom style = "thin"><color indexed = "64" / >< / bottom><diagonal / >< / border>
< / borders>

<cellStyleXfs count = "1">
	<xf numFmtId = "0" fontId = "0" fillId = "0" borderId = "0"><alignment vertical = "center" / >< / xf>
< / cellStyleXfs>

<cellXfs count = "5">
	<xf numFmtId = "0" fontId = "0" fillId = "0" borderId = "0" xfId = "0"><alignment vertical = "center" / >< / xf>
	<xf numFmtId = "0" fontId = "0" fillId = "0" borderId = "1" xfId = "0" applyBorder = "1"><alignment vertical = "center" / >< / xf>
	<xf numFmtId = "0" fontId = "0" fillId = "0" borderId = "1" xfId = "0" applyBorder = "1" applyAlignment = "1"><alignment horizontal = "center" vertical = "center" / >< / xf>
	<xf numFmtId = "0" fontId = "0" fillId = "2" borderId = "1" xfId = "0" applyFill = "1" applyBorder = "1" applyAlignment = "1"><alignment horizontal = "center" vertical = "center" / >< / xf>
	<xf numFmtId = "0" fontId = "0" fillId = "0" borderId = "1" xfId = "0" applyBorder = "1" applyAlignment = "1"><alignment horizontal = "left" vertical = "center" / >< / xf>
< / cellXfs>

<cellStyles count = "1">
	<cellStyle name = "常规" xfId = "0" builtinId = "0" / >< / cellStyles>
	<dxfs count = "0" / >
	<tableStyles count = "0" defaultTableStyle = "TableStyleMedium2" defaultPivotStyle = "PivotStyleLight16" / >
	<extLst>
		<ext uri = "{EB79DEF2-80B8-43e5-95BD-54CBDDF9020C}" xmlns:x14 = "http://schemas.microsoft.com/office/spreadsheetml/2009/9/main">
			<x14:slicerStyles defaultSlicerStyle = "SlicerStyleLight1" / >
		< / ext>
		<ext uri = "{9260A510-F301-46a8-8635-F512D64BE5F5}" xmlns:x15 = "http://schemas.microsoft.com/office/spreadsheetml/2010/11/main"><x15:timelineStyles defaultTimelineStyle = "TimeSlicerStyleLight1" / >
		< / ext>
	< / extLst>

< / styleSheet>
*/




///
//Cell->s->style->xf numFmtId = 14(2014 / 1 / 1)   numFmt = 17 (Jan - 15) ...

/*
The s attribute references a style xf entry in styles.xml. The style xf in turn references a number format mask. To identify a cell that contains a date, you need to perform the style xf -> numberformat lookup, then identify whether that numberformat mask is a date/time numberformat mask (rather than, for example, a percentage or an accounting numberformat mask).

The style.xml file has elements like:

<xf numFmtId="14" ... applyNumberFormat="1" />
<xf numFmtId="1" ... applyNumberFormat="1" />
These are the xf entries, which in turn give you a numFmtId that references the number format mask.

You should find the numFmts section somewhere near the top of style.xml, as part of the styleSheet element

<?xml version="1.0" encoding="UTF-8" standalone="yes" ?>
<styleSheet xmlns="http://schemas.openxmlformats.org/spreadsheetml/2006/main">
<numFmts count="3">
<numFmt numFmtId="164" formatCode="[$-414]mmmm\ yyyy;@" />
<numFmt numFmtId="165" formatCode="0.000" />
<numFmt numFmtId="166" formatCode="#,##0.000" />
</numFmts>
The number format id may be here, or it may be one of the built-in formats. Number format codes (numFmtId) less than 164 are "built-in".

The list that I have is incomplete:

0 = 'General';
1 = '0';
2 = '0.00';
3 = '#,##0';
4 = '#,##0.00';

9 = '0%';
10 = '0.00%';
11 = '0.00E+00';
12 = '# ?/?';
13 = '# ??/??';
14 = 'mm-dd-yy';
15 = 'd-mmm-yy';
16 = 'd-mmm';
17 = 'mmm-yy';
18 = 'h:mm AM/PM';
19 = 'h:mm:ss AM/PM';
20 = 'h:mm';
21 = 'h:mm:ss';
22 = 'm/d/yy h:mm';

37 = '#,##0 ;(#,##0)';
38 = '#,##0 ;[Red](#,##0)';
39 = '#,##0.00;(#,##0.00)';
40 = '#,##0.00;[Red](#,##0.00)';

44 = '_("$"* #,##0.00_);_("$"* \(#,##0.00\);_("$"* "-"??_);_(@_)';
45 = 'mm:ss';
46 = '[h]:mm:ss';
47 = 'mmss.0';
48 = '##0.0E+0';
49 = '@';

27 = '[$-404]e/m/d';
30 = 'm/d/yy';
36 = '[$-404]e/m/d';
50 = '[$-404]e/m/d';
57 = '[$-404]e/m/d';

59 = 't0';
60 = 't0.00';
61 = 't#,##0';
62 = 't#,##0.00';
67 = 't0%';
68 = 't0.00%';
69 = 't# ?/?';
70 = 't# ??/??';
The missing values are mainly related to east asian variant formats.

*/