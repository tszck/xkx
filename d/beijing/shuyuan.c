// Room: /beijing/shuyuan.c

inherit ROOM;

void create()
{
	set("short", "書院");
	set("long", @LONG
這裏是書院的講堂，窗明幾淨，一塵不染。一位莊重嚴肅的老者坐
在太師椅上講學，那就是京城的大儒顧炎武了。在他的兩側坐滿了求學
的學生。一張古意盎然的書案放在顧先生的前面，案上擺着幾本翻開了
的線裝書籍。顧先生的身後是一個書架(shujia)講堂內多歷代楹聯石刻，
足見書院歷史的悠久。值得一提的是嵌在講堂前左壁的學規(xuegui)。
LONG );
	set("exits", ([
		"south" : __DIR__"di_an4",
	]));
	set("item_desc", ([
		"xuegui" : "日講經書三起，日看綱目數頁。"  
			"\n通曉時務物理，參讀古文詩賦。" 
			"\n讀書必須過筆，會課按時蚤完。"
			"\n夜讀仍戒晏起，疑誤定要力爭。\n\n"
			"求學需繳學費五十兩\n",
	]));
	set("objects", ([
		__DIR__"npc/gu": 1,
	]));
	set("coor/x", -220);
	set("coor/y", 4090);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	me->set_temp("mark/朱", 0);
	return 1;
}
