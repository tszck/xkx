inherit ROOM;

void create()
{
	set("short", "王府井大街");
	set("long", @LONG
這裏是王府井大街的盡頭。北邊是一座富麗堂皇的大樓，門額上懸
掛一方橫匾，寫着“康親王府”四個大字，乃是康熙皇帝親筆。西邊通
往地安門。
LONG );
        set("outdoors", "beijing");
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"di_an1",
		"south" : __DIR__"wangfu2",
		"north" : __DIR__"kang1",
	]));
	set("coor/x", -180);
	set("coor/y", 4070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
