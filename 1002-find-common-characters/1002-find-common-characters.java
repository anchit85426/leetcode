class Solution {
    public List<String> commonChars(String[] words) {  
        HashMap<Character,Integer> map=new HashMap<>();
        String s=words[0];
        for(int i=0;i<s.length();i++){
            char c=s.charAt(i);
            map.put(c,map.getOrDefault(c,0)+1);
        }
        for(int i=1;i<words.length;i++){
            HashMap<Character,Integer>map1=new HashMap<>();
            String s1=words[i];
            for(int j=0;j<s1.length();j++){
                char c=s1.charAt(j);
                map1.put(c,map1.getOrDefault(c,0)+1);
            }
            for(Character key:map.keySet()){
                if(map1.containsKey(key))
                {
                    map.put(key,Math.min(map1.get(key),map.get(key)));
                }
                else{
                    map.put(key,0);
                }
                
            }
        }
        List<String> list=new ArrayList<>();
        for(Character key:map.keySet()){
            System.out.println(map.get(key));
            if(map.get(key)>=1){
                for(int i=0;i<map.get(key);i++){
                    list.add(key+"");
                }
            }
        }
        return list;
    }
}