//room: changl5.c
inherit ROOM;

void create()
{
	set("short","畫廊");
	set("long",@LONG
這是一條非常精美的長廊，柱子和欄杆是用華貴的紫檀木製成，上
面雕飾着美麗的圖畫，畫工精巧，美不勝收。地板不知是用什麼材料做
的，走在上面毫無聲息，你只感到腳下軟軟的，非常舒服。走廊西面是
兵器庫。
LONG );
	set("exits",([
		"east" : __DIR__"changl1",
		"west" : __DIR__"wuqiku",
		"north" : __DIR__"changl9",
		"south" : __DIR__"changl6",
	]));
	set("no_clean_up", 0);
	set("coor/x", -51020);
	set("coor/y", 30150);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}