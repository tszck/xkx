// Room: /d/city/yaqianroom.c
// Last modified by winder 2002.11.11
 
inherit ROOM;

int room_status = 0;
int *res = allocate(5);

int random2 (int i)
{
	return (random(i)+uptime()) % i;
}

mapping qians = ([
	"dqq" : "大乾籤",
	"dkq" : "大坤籤",
	"xqq" : "小乾籤",
	"xkq" : "小坤籤",
	"qq"  : "乾籤",
	"kq"  : "坤籤",
]);

void create()
{
	set("short", "押籤房");
	set("long", @LONG
一羣人圍着紫檀木大桌而坐，首席座着一位精瘦的籤客，正在一本
正經地從鑲金黑盒裏慢悠悠一根一根往外抽出乾坤籤，碼在桌面上。

    牆上有一匾寫着：
        大乾籤（全部五根皆爲乾籤）：一贏三十二
        大坤籤（全部五根皆爲坤籤）：一贏三十二
        小乾籤（連續四根皆爲乾籤）：一贏十六
        小坤籤（連續四根皆爲坤籤）：一贏十六
          乾籤（任意三根皆爲乾籤）：一贏二
          坤籤（任意三根皆爲坤籤）：一贏二

    匾角有一個牌子(paizi)。
LONG);

	set("item_desc",([
		"paizi" : "押大乾籤：  qian dqq <amount> <money>\n"+  
			"押大坤籤：  qian dkq <amount> <money>\n"+  
			"押小乾籤：  qian xqq <amount> <money>\n"+  
			"押小坤籤：  qian xkq <amount> <money>\n"+  
			"押乾籤：     qian qq <amount> <money>\n"+  
			"押坤籤：     qian kq <amount> <money>\n\n"+
			"爲免破產跳樓  限押一兩黃金\n",
	]));
	set("exits",  ([  /*  sizeof()  ==  1  */
		"north" : __DIR__"youxiting",
	]));
	set("objects",  ([  /*  sizeof()  ==  1  */
		__DIR__"npc/qianke" : 1,
	]));
	set("light_up", 1);
	set("no_fight", 1);
	set("no_beg", 1);
	set("coor/x", -5040);
	set("coor/y", 1010);
	set("coor/z", 10);
	setup();
}

void init()
{
	add_action("do_qian","qian");

	if (room_status > 0) return;

	remove_call_out("gamble_prepare");
	remove_call_out("gamble_start");
	remove_call_out("gamble_perform");
	remove_call_out("gamble_finish");
	call_out("gamble_prepare",2);
	room_status = 1;
}

int do_qian(string arg)
{
	object me = this_player();
	string what;
	int amount;
	string money;
	object ob;

	if (!arg || sscanf(arg,"%s %d %s",what,amount,money) != 3)
		return notify_fail("請使用：  qian <押籤種類> <數目> <貨幣>\n");
	if (what != "dqq" && what != "dkq" && what != "xqq" &&
		what != "xkq" && what != "qq" && what != "kq")
		return notify_fail("你要押什麼籤？\n");
	ob = present(money+"_money", me);
	if (! ob) return notify_fail("你身上沒有這種貨幣。\n");
	if (amount < 1) return notify_fail("請多押一些錢。\n");
	if (amount > ob->query_amount())
		return notify_fail("你身上的錢不夠押。\n");
	if (amount * (ob->query("base_value")) > 10000 )
		return notify_fail("你想豪賭啊，拜託！官兵就進來了。\n");
	if (me->query_temp("gamble_qian/amount") > 0)
		return notify_fail("你已經押過了。\n");
	if (room_status > 1)
		return notify_fail("現在正在賭呢，稍等片刻。\n");

	me->set_temp("gamble_qian/kind",what);
	me->set_temp("gamble_qian/amount",amount);
	me->set_temp("gamble_qian/money",money);
	message_vision(sprintf("$N拿出%s%s%s，押在%s上。\n", chinese_number(amount), ob->query("base_unit"), ob->query("name"), qians[what]), me);
	if (amount == ob->query_amount()) destruct (ob);
	else ob->add_amount(-amount);

	return 1;
}

int valid_leave(object me, string dir)
{
	if (dir == "north")
	{
		if(me->query_temp("gamble_qian/amount") > 0)
			message_vision("$N扔下押籤的錢。\n",me);
		me->delete_temp("gamble_qian");
	}
	return ::valid_leave(me,dir);
}

void gamble_prepare()
{
	object room = this_object();
	object *inv;
	int i;

	tell_room(room,"籤客將一大束簽在桌上嘩啦啦地迅速洗了一遍。\n");
	tell_room(room,"洗籤之後，籤客啪地一聲將籤裝入鑲金黑盒，叫道：開押！\n");

	inv=all_inventory();
	i=sizeof(inv);
	while(i--)
	{
		if(userp(inv[i]))
		{
			room_status = 1;
			call_out("gamble_start",25);
			return;
		}
	}
	room_status=0;
	return;
}

void gamble_start()
{
	object room = this_object();
	tell_room(room,"籤客喊聲：停押！\n");
	tell_room(room,"然後閉上眼睛，將鑲金黑盒打開從裏開始往外抽籤。\n");
	room_status = 2;
	call_out("gamble_perform",3,0);
	call_out("gamble_perform",6,1);
	call_out("gamble_perform",9,2);
	call_out("gamble_perform",12,3);
	call_out("gamble_perform",15,4);
	call_out("gamble_finish",18);
}

void gamble_perform(int i)
{
	object room = this_object();

	switch (random2(2))
	{
		case 0:
		{
			tell_room(room,"\n□□    坤    籤    □□\n");
			res[i] = 0;
			break;
		}
		case 1:
		{
			tell_room(room,"\n□□    乾    籤    □□\n");
			res[i] = 1;
			break;
		}
	}
}

void player_wins(object who, int total)
{
	object money =new("/clone/money/"+who->query_temp("gamble_qian/money"));
	int amount = who->query_temp("gamble_qian/amount");
	total = total * amount;
	money->set_amount(total);
	message_vision(sprintf("$N贏了%s%s%s！\n", chinese_number(total), money->query("base_unit"), money->query("name")), who);
	money->move(who);
}

void player_loses(object who, int total)
{
	object money =new("/clone/money/"+who->query_temp("gamble_qian/money"));
	total = who->query_temp("gamble_qian/amount");
	message_vision(sprintf("籤客將$N押在盤中的%s%s%s收走。\n", chinese_number(total), money->query("base_unit"), money->query("name")), who);
	destruct(money);
}

void gamble_finish()
{
	string win;
	int total, i;
	object room = this_object();
	object *list = all_inventory(room);
	if (res[0]==1 && res[1]==1 && res[2]==1 && res[3]==1 && res[4]==1)
	{
		total = 32;
		win = "dqq";
	}
	else if (res[0]==0 && res[1]==0 && res[2]==0 && res[3]==0 && res[4]==0)
	{
		total = 32;
		win = "dkq";
	}
	else if ((res[0]==1 && res[1]==1 && res[2]==1 && res[3]==1) ||
		(res[1]==1 && res[2]==1 && res[3]==1 && res[4]==1))
	{
		total = 16;
		win = "xqq";
	}
	else if ((res[0]==0 && res[1]==0 && res[2]==0 && res[3]==0) ||
		(res[1]==0 && res[2]==0 && res[3]==0 && res[4]==0))
	{
		total = 16;
		win = "xkq";
	}
	else
	{
		int r = 0;
		total = 2;
		for (i = 0; i < 5; i++) r += res[i];
		if (r >= 3) win = "qq";
		else win = "kq";
	}
	tell_room(room,"\n籤客睜開眼睛，迅速看一眼桌面，叫道："+qians[win]+"！\n");
	i = sizeof(list);
	while (i--)
	{
		if (!userp(list[i])) continue;
		if (list[i]->query_temp("gamble_qian/kind") == win)
			player_wins(list[i],total);
		else if (list[i]->query_temp("gamble_qian/kind"))
			player_loses(list[i],total);
		list[i]->delete_temp("gamble_qian");
	}
	tell_room(room,"\n");
	call_out("gamble_prepare",5);
}
