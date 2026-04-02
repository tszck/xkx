// Room: /d/xiangyang/yaopu.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "藥鋪");
	set("long", @LONG
藥鋪不大，卻異常的整潔；正面是櫃檯，櫃檯後面是個大
櫃子幾百個小抽屜上一一用紅紙標着藥材的名稱；靠近屋頂的
牆上懸着一塊黑底金字的匾額，寫着“妙手回春”。地下幾個
夥計正在分揀剛剛收購來的草藥。東邊一張小矮桌兒，上面放
着筆墨紙硯，桌後坐着一位老郎中。一股刺鼻藥味充滿了整個
房間。
LONG );
	set("exits", ([
		"north" : __DIR__"eastjie1",
	]));
	set("objects", ([
		"/d/city/npc/huoji" : 1,
	]));
	set("coor/x", -490);
	set("coor/y", -520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}