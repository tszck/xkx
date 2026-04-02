// /beijing/hangang.c
// Last modified by winder 2003.10.10

inherit ROOM;

void create()
{
	set("short", "塘沽口");
	set("long", @LONG
這裏就是大海之濱，浪花拍打着礁石，發出陣陣響聲，海面上一羣
羣海鷗『歐歐..』地叫着，不時有魚兒躍出海面，濺起層層的浪花。邊
上有艘大船 (chuan)，船上坐着幾個漁夫打扮的人，乘船可渡過大海到
達海的另一端。西面過天津城就是北京了，東面是一望無際的大海。
LONG );
	set("exits", ([
                "west" : __DIR__"road10",
	]));
	set("item_desc", ([
                "chuan" : "一艘大帆船，造得很結實，看來可以出遠海的。\n",
	]));
	set("objects", ([
		__DIR__"npc/flowerg":2,
		"/d/shenlong/npc/chuanfu" : 1,
		"/d/shenlong/npc/xiucai" : 1,
	]));
	set("outdoors", "huabei");
	set("coor/x", 500);
	set("coor/y", 2000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
