// eventd.c
// 自然奇觀系統主程序
// for XKX100 , by Sir 2003.11.3

#include <dbase.h>
#include <ansi.h>
#include <localtime.h>
int start;

// 待觸發的事件
// 登記在某個絕對的時間啓動事件
// 設定的參數是零或負數
// 比如：month = 0  day = 0   hour = -5    表示實際時間每天早上5點鐘 
//	 month = -8 day = -15 hour = -5    表示實際時間每年8月15的5點鐘 
mapping *event_list = ({	
(["month" :  0, "day" :  0, "hour"  : -7,  "ename"  : "emei.c",     "cname" : "峨嵋金頂日出" ]), //早上7點
(["month" :  0, "day" : -15,"hour"  : -23, "ename"  : "wuliang.c",  "cname" : "無量山玉壁劍舞"]), //每月15日晚11點
(["month" :  0, "day" :  0, "hour"  : -22, "ename"  : "tianchi.c",  "cname" : "長白山天池流星"]), //每晚10點
(["month" : -8, "day" : -15,"hour"  : -10, "ename"  : "qiantang.c", "cname" : "錢塘江潮信"]), //每年8月15日10點
(["month" :  0, "day" :  0, "hour"  : -17, "ename"  : "hspb.c",     "cname" : "衡山水簾洞瀑布"]), //每日下午5點
});


void create()
{
        int i;
        seteuid(ROOT_UID);

        message("channel:sys", HIR"【自然奇觀】自然奇觀已經啓動。\n"NOR, users());
        message("channel:sys", HIR"【自然奇觀】系統已登記的自然奇觀如下:\n"NOR, users());
        
        for ( i = 0 ; i < sizeof(event_list); i++)
        {
        	message("channel:sys", HIR"【自然奇觀】"+event_list[i]["cname"]+"。\n"NOR, users());
        }
        
        set_heart_beat(30);      // 每分鐘心跳一次
}


// 每分鐘心跳一次，1,10時檢查所有的事件
void heart_beat()
{
        mixed *lt;
        object eob;
        int i,num;
        int  month,day,hour;
        string time;
        
        lt = localtime(time());
        num = 0;
        
        if ( start == 59 ) 
             { 
             	start = 0;
              }
        else start = start + 1; 
        
        time = ""; 
        
        time = chinese_number( start );
        
//        message("channel:sys",HIR"【自然奇觀】 這個時間段內心跳"+time+"次\n"NOR, users());
        
        if ( start == 1 || start == 10) 
        {      
        
        for ( i = 0 ; i < sizeof(event_list); i++)
        	{
        		month = event_list[i]["month"];
        		day   = event_list[i]["day"];
        		hour  = event_list[i]["hour"];
        			
        		if (month < 0) month = -month-1; 
        			else month += lt[LT_MON] ;
        		if (day < 0)   day = -day;     
        			else day += lt[LT_MDAY];
        		if (hour < 0)  hour = -hour;   
        			else hour += lt[LT_HOUR];
        	if (  month == lt[LT_MON] && day == lt[LT_MDAY] && hour == lt[LT_HOUR])
      	  		{
        		    if (start == 1)
        		    message("channel:rumor", HIM"【謠言】"+"聽說"+event_list[i]["cname"]+"蔚爲奇觀，不少江湖人士紛紛前往觀賞。\n"NOR, users());
        		    else
        		    {
        		    	eob = new (EVENT_DIR + event_list[i]["ename"]);
        		    	destruct(eob);
        		    }	        
        		 }
        	else
        		continue;
        	}
        } 
}