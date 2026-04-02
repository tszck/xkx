//cave.c

inherit ROOM;

void create()
{
	set("short", "湖心小洞");
	set("long",
	     "這裏是潭中的一個小洞，裏面零零落落的有幾塊石頭。\n"
	);
	set("objects" , ([
		__DIR__"item/stone" : 1,
	]) );
	set("coor/x", -1510);
	set("coor/y", -1020);
	set("coor/z", -40);
	setup();
	replace_program(ROOM);
}
