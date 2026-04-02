// Room: /city/chenglou.c
// Last Modified by winder on Apr. 10 2000

#include <room.h>

inherit ROOM;
string look_yangzhou();
string yangzhou_map = @TEXT
                                             大驛道 古邗溝邊-古邗溝邊-古邗溝邊
                                               ｜  ／
         堂屋 魁星閣         <瘦西湖> <黃河>-鎮淮門  <崇雅書院>    |~~|
          ｜       ＼          |｜|            ｜        ｜        |~~|
       資政書院------草河北街--虹橋---------北門大街---瓊花街-----開明橋-<東城>
                   ／   ｜     |~~|            ｜        ｜        |~~|
              忠烈祠    ｜     |~~|  小寶齋-十里長街--富春茶社     |小|
                        ｜     |草|            ｜                  |秦|
      <桃花村>          ｜     |河|廣陵當鋪-十里長街-<淮揚賭場>    |淮|
         ｜             ｜     |~~|            ｜                  |河|
         ｜ <揚州官衙>  ｜     |~~|  <武廟>-十里長街--<醉仙樓>     |~~|
         ｜     ｜      ｜     |~~|            ｜        ｜        |~~|
<洛陽>-通泗門-通泗街-草河小街-通泗橋--------十里長街---甘泉街-----寧海橋-<東城> 
              ／   ／   ｜     |~~|            ｜        ｜        |~~|
   <財主家> ／ <武道場> ｜     |~~|彥明錢莊-十里長街-<秦淮客寓>    |~~|
      ｜  ／            ｜     |~~|            ｜                  |小|
  小草河側巷-玉器店     ｜     |官|  雜貨鋪-十里長街-藥鋪  堂屋    |秦|
    ／   ＼             ｜     |河|            ｜           ｜     |淮|
成衣店 維揚花店-<禪智寺>｜     |~~|  打鐵鋪-十里長街-武館 容膝園   |河|
                     ＼ ｜     |~~|            ｜           ｜     |~~|
        <小玲瓏山館>-草河南街-太平橋--------南門大街------禾嘉街-小東門橋-<東城>
                        ｜     |~~|            ｜           ｜     |~~|
                       何園    |~~|          安定門      <城守署>  |~~|
                        ｜     |~~|            ｜         -        |~~|
                     何園後院  |~~|~~~~~~~~~|渡江橋|~~~~~~~~~~~~~~~|~~|
                               ^~~^~~~~~~~~~^  ｜  ^~~~~~~~~~~~~~~~^~~^

TEXT;

void create()
{
	set("short", "鎮淮門城樓");
	set("long", @LONG
沿着城門邊上的的石階拾級而上，上得城牆。城牆上建一座城樓，
飛檐高挑，極爲雄偉，邊上是敵樓，幾個士兵在警戒。城樓上有幾個遊
人，有的在俯視整個揚州城，有的遠眺北面的平山堂。
LONG );
	set("exits", ([
		"down"    : __DIR__"beimen",
	]));
	set("item_desc", ([
        "揚州" : (: look_yangzhou :),
        "yangzhou" : (: look_yangzhou :),
        "city" : (: look_yangzhou :),
        "揚州城" : (: look_yangzhou :),
        "平山堂" : "平山堂籠罩在雲煙之中，據說知州常在那裏飲酒作樂。\n"
	]));
	set("no_clean_up", 0);
	set("outdoors", "yangzhouw");
	set("coor/x", 10);
	set("coor/y", 100);
	set("coor/z", 10);
	setup();
}

string look_yangzhou()
{
	object me = this_player();
	object room;
//	write( yangzhou_map );
	me->start_more(yangzhou_map);
	me->add_temp("yangzhou_look", 1);
	if (random(5) > 2 && me->query_temp("yangzhou_look") )
		write("\n\n你彷彿看到些什麼，卻有沒看清楚。\n");
	else if (random(5) > 2 && me->query_temp("yangzhou_look") > 2 )
		write("\n\n你好象看到了一些東西，卻始終沒看明白。\n");
	else if (random(5) > 2 && me->query_temp("yangzhou_look") > 5 )
	{
		write("你發現揚州官衙裏有個人在躥來躍去的。\n");
		return "";
	}
	if ( (int)me->query_temp("yangzhou_look") > 3 && random(3) == 0)
	{
		message("vision", "你伸長脖子，探出去想看的更清楚一點，卻一不小心掉了下去！\n", me);
		message("vision", "只見"+me->name()+"身子過多的掛出城牆外，雙手搖搖了，想控制住平衡，\n終究沒有成功，一個倒栽蔥掉了下去。\n", environment(me), ({me}));
		if( !room = find_object(__DIR__"beimen") )
			room = load_object(__DIR__"beimen");

		if( room = find_object(__DIR__"beimen") )
		{
			message( "vision", "只見一團黑影從天而降，原來是" + me->name() + "從城牆上掉了下來!\n", room );
			me->move( room );
			if ( me->query_skill("dodge", 1) < 20 ) me->unconcious();
			else if ( me->query_skill("dodge", 1) < 40 )
				tell_object(me,"你盡力在空中控制自己的姿勢，還是屁股着地。\n");
			else
				tell_object(me,"你在空中一翻身，輕巧自如的落在地面。\n");
		}
	}
	return "";
}

int valid_leave(object me, string dir)
{
	if ( me->query_temp("yangzhou_look") )
		me->delete_temp("yangzhou_look");
	return ::valid_leave(me, dir);
}