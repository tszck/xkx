// buwei3.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "後堂");
	set("long", @LONG
這裏是華山總所的後堂。梁間一塊匾上寫着“以氣御劍”四個大字，
掌上佈置肅穆，兩壁懸着一柄柄長劍，劍鞘黝黑，劍穗陳舊，想是華山
派前代各宗師的佩劍，華山派今日在武林中這麼大的聲譽，不知道曾有
多少奸邪惡賊，喪生在這些前代宗師的長劍之下。正中神案的牆上是華
山派開山祖師風祖師的畫象。畫象神情清雋，非常傳神。神案上香爐裏
插着三柱清香，香煙裊裊上升，散發着一股檀香味。西面有扇門通往外
面的正廳。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"buwei1",
	]));
	set("objects", ([ /* sizeof() == 2 */
		CLASS_D("huashan")+"/first": 1,
	]));
	set("valid_startroom","1");

	set("coor/x", -850);
	set("coor/y", 220);
	set("coor/z", 120);
	setup();
	"/clone/board/huashan_b"->foo();
	replace_program(ROOM);
}
