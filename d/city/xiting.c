// Room: /city/xiting.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "西廳");
	set("long", @LONG
這裏是衙門的西廳，乃是知府的書房。書案上凌亂地放着幾本發黃
的古籍。引起你的注意的是牆上掛着一幅很大的地圖(ditu)。
LONG );
	set("item_desc", ([
		"ditu" : "這是一幅揚州市區和市郊的地圖，上面有各種顏色的圈圈點點，顯見主人經常\n"
		"看它，而且看得頗爲仔細，似乎在尋找一個特別的地點。\n",	
	]));
	set("exits", ([
		"east" : __DIR__"zhengtang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -21);
	set("coor/y", 2);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}