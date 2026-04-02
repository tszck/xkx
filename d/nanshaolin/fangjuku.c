// Room: /d/nanshaolin/fangjuku.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "防具庫");
	set("long", @LONG
這是一間很大的房間，靠牆整齊地放着一個個大櫃子，不少櫃子門
敞開着，露出裏面的各種防具，品種之多，是你生平僅見。一位灰衣僧
人正埋頭整理一堆破損的護具。連你進來也沒有注意。
LONG );
	set("exits", ([
		"north" : __DIR__"lshuyuan",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/fangtu" : 1,
	]));
	set("coor/x", 1790);
	set("coor/y", -6210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


