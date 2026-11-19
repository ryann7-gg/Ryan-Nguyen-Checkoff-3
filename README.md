# Ryan-Nguyen-Checkoff-3

My topic is buffer overflows and memory vulnerabilities, specifically integer overflows and memory safety. 

I explored how attackers can exploit code to cause integers to overflow, which can cause undefined behavior. This could allow the attacker to execute code, or gain access to private data. 

I learned how it works, and how to protect against it. Integer overflows occur when the value is too large for integers to store, so the value loops back around. 

I made two interesting discoveries. 
    
Firstly, there is a real-world example of this with Android's Stagefright in 2015. It was responsible for processing media files, including MP4 files. Attackers could create files of specific sizes and data to cause integer overflows, which allowed them to execute code. 

Secondly, integer overflows can occur in security checks. Someone might try to add two values together, and check if it is within the limits, but the addition could cause the integer overflow. This would make the check pass, even though it should fail. 