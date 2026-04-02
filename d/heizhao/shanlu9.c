// Room: /heizhao/shanlu9.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
又行了一陣，正覺脣乾口渴，忽聽遠處傳來隱隱水聲，你當即
加快腳步。空山寂寂，那水聲在山谷間激盪迴響，轟轟洶洶，愈走
水聲愈大，待得走上嶺頂，只見一道白龍似的大瀑布從對面雙峯之
間奔騰而下，聲勢甚是驚人。從嶺上望下去，瀑布旁有一間草屋。
LONG );
	set("outdoors", "taoyuan");
	set("no_clean_up", 0);
	set("exits", ([
		"northdown" : __DIR__"pubu",
		"eastdown"  : __DIR__"shanlu8",
	]));
	set("coor/x", -5020);
	set("coor/y", -1290);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}