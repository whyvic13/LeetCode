public class ValidWordAbbr {

	    HashMap<String, HashSet<String>> map = new HashMap<>();
	    
	    public ValidWordAbbr(String[] dictionary) {
	        for (String dic : dictionary) {
	            String key = getKey(dic);
	            if (map.containsKey(key)) {
	                map.get(key).add(dic);
	            } else {
	            	HashSet<String> hashSet = new HashSet<>();
	            	hashSet.add(dic);
	                map.put(key, hashSet);
	            }
	        }
	    }
	    
	    public boolean isUnique(String word) {
	        String key = getKey(word);
	        return !map.containsKey(key) || (map.get(key).contains(word) && map.get(key).size() == 1);
	    }
	    
	    private String getKey(String word) {
	        String key = "";
	        if(word.length() > 2){
	            key = word.charAt(0) + Integer.toString(word.length() - 2) + word.charAt(word.length() - 1);
	        }
	        else {
	            key = word;
	        }
	        return key;
	    }
	}
