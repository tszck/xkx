// Room: /d/shaolin/gulou6.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "鼓樓六層");
	set("long", @LONG
沿窗洞吹進一陣陣凌厲的山風，寒意浸人。北望可見松林的
盡頭，少室山的頂峯處，有一片小小的平地，正中植着三棵巨松；
中間又似乎有什麼東西正閃閃發光。樓上傳來一陣陣沉悶的鼓聲。
LONG );
	set("exits", ([
		"up" : __DIR__"gulou7",
		"down" : __DIR__"gulou5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 830);
	set("coor/z", 160);
	setup();
	replace_program(ROOM);
}