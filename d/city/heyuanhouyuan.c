// Room: /city/heyuanhouyuan.c

inherit ROOM;

void create()
{
	set("short", "何園後院");
	set("long", @LONG
這裏四周描金漆銀，裝扮得富麗堂皇，別有氣派，門廊下掛着絲雀
畫眉，叫聲婉轉動聽，幾株名貴的珊瑚就放在院中，四下散放着一些躺
椅，以供在院中休息。
LONG );
	set("exits", ([
		"north" : __DIR__"heyuan",
	]));
        set("objects", ([
		__DIR__"npc/he": 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", -52);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}