//ROOM: xiaoqiao.c

inherit ROOM;

void create()
{
	set("short", "紫菱橋");
	set("long",@LONG
細竹搭就的一座小小拱橋，竹製的欄杆雕有別致的花紋，橋的北端
隱隱有一座小小木屋。站在橋上，你覺的心曠神怡，久久不願離去。
LONG );
	set("outdoors", "yanziwu");
	set("exits", ([
        	"north" : __DIR__"tingyu",
        	"east"  : __DIR__"xiaojing",
	]));
	set("no_clean_up", 0);
	set("coor/x", 810);
	set("coor/y", -1490);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}