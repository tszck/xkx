// yacairoom.c.
// Last modified by winder 2002.11.11

inherit ROOM;

void create ()
{
	set("short", "押彩房");
	set("long", @LONG
這裏擺着一個八仙桌，中間擺着一個銀盤。賭客們正聚精會神地下
賭。正席是一位胖子，手裏不斷玩弄着一對玉骰，他就是這裏的莊東。
    牆上掛有一個匾(bian)。
LONG);

	set("item_desc", (["bian" : "
ya tc <數量> <coin|silver|gold> 押頭彩(兩數順序及點數均正確)       一賠卅五
ya dc <數量> <coin|silver|gold> 押大彩(兩數點數正確)               一賠十七
ya sd <數量> <coin|silver|gold> 押雙對(兩數相同且均爲偶數)         一賠十一
ya kp <數量> <coin|silver|gold> 押空盤(兩數不同且均爲偶數)         一賠五
ya qx <數量> <coin|silver|gold> 押七星(兩數之和爲七)               一賠五
ya dd <數量> <coin|silver|gold> 押單對(兩數均爲奇數)               一賠三
ya sx <數量> <coin|silver|gold> 押散星(兩數之和爲三、五、九、十一) 一賠二
每盤按從上到下的順序只出現一種點型(頭彩和大彩可同時出現)，其他情況都算莊家贏。
"
	]));
	set("exits", ([
		"west" : __DIR__"shaiziting",
	]));
	set("objects", ([
		__DIR__"npc/zhuangjia" : 1,
	]));

	set("no_fight", 1);
	set("no_beg", 1);
	set("no_magic", 1);
	set("no_clean_up", 1);
	set("coor/x", 22);
	set("coor/y", 9);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
