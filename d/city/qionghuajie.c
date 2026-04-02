// Room: /yangzhou/qionghuajie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","瓊花街");
	set("long",@LONG
瓊花街雖是青石鋪地，地面卻多有裂縫，也不平整，大概瓊花街是
條老街的緣故。兩邊的屋檐密密重重，傍河而建，數條小巷穿插其中。
行人大多匆匆而過，偶然有馬蹄磕擊青石的“噠噠”聲。北面就是崇雅
書院，朱先生在此傳授學問。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"east"   : __DIR__"kaimingqiao",
		"west"   : __DIR__"beimendajie",
		"south"  : __DIR__"chaguan",
		"north"  : __DIR__"shuyuan",
	]));
	set("coor/x", 20);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}