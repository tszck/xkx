// Room: /d/yueyang/qiuyueqiao.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "秋月橋");
	set("long", @LONG
位於湘妃祠引道左側，爲半園石拱橋，橋下爲一片荷塘。拱橋的半
園拱倒映在荷塘中恰似一輪跳動的秋月。傳說站在秋月橋上觀秋月倒映
在秋月井中，能看見嫦娥抱着玉兔守着廣寒宮的寂寞情景，只可惜這口
井早已不復存在了。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"south"     : __DIR__"xiaolu7",
		"northup"   : __DIR__"qiuyueting",
	]));
	set("coor/x", -1670);
	set("coor/y", 2330);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
