inherit ROOM;

void create()
{
	set("short", "康府花園");
	set("long", @LONG
這是一個小花園，雖然花兒不太多，卻十分幽雅清潔，顯是平日
有人修整打掃。花園北邊是一間佛堂。
LONG );
        set("outdoors", "beijing");
	set("no_clean_up", 0);
	set("exits", ([
  		"east"  : __DIR__"kang3",
  		"north" : __DIR__"fotang",
	]));
	set("coor/x", -181);
	set("coor/y", 4082);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
