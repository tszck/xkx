// Room: /d/lingxiao/walle1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "城頭");
	set("long", @LONG 
這是凌霄城的城頭，從這極目遠望，只見萬裏雪山，一片蒼茫。黃
雲萬丈之下，無數起伏的山脈向東奔騰而去。沉寂的雪嶺之間，只偶爾
傳來一陣陣狼嗷。
LONG );
	set("outdoors", "lingxiao");
	set("exits", ([
		"east"     : __DIR__"walle2",
		"westdown" : __DIR__"gate",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	])); 
	set("coor/x", -30990);
	set("coor/y", -8930);
	set("coor/z", 150);
	setup();
	replace_program(ROOM);
}

