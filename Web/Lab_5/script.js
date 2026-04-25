 // 1. LocalStorage Logic
    const systemData = {
      os: navigator.platform,
      browser: navigator.userAgent,
      lang: navigator.language,
      timeSaved: new Date().toLocaleString()
    };
    localStorage.setItem('os_info', JSON.stringify(systemData));
    document.getElementById('site-footer').innerHTML += `<p>${localStorage.getItem('os_info')}</p>`;

    // 2. Fetch Comments (JSONPlaceholder)
    async function fetchComments() {
      const variant = 18; // Встав свій номер варіанту тут
      const container = document.getElementById('comments-container');

      try {
        const response = await fetch(`https://jsonplaceholder.typicode.com/posts/${variant}/comments`);
        const comments = await response.json();
        container.innerHTML = ''; // Clear loader

        comments.forEach(c => {
          const commentEl = document.createElement('div');
          commentEl.className = 'comment';
          commentEl.innerHTML = `<strong>${c.email}</strong><p>${c.body}</p>`;
          container.appendChild(commentEl);
        });
      } catch (e) {
        container.innerHTML = '<p>Не вдалося завантажити коментарі.</p>';
      }
    }
    fetchComments();

    // 3. Modal logic
    const modal = document.getElementById('modalOverlay');
    const closeBtn = document.getElementById('closeBtn');

    setTimeout(() => {
      modal.style.display = 'flex';
    }, 60000); // 1 minute delay

    closeBtn.onclick = () => modal.style.display = 'none';
    window.onclick = (event) => {
      if (event.target == modal) modal.style.display = 'none';
    };

    // 4. Dark/Light Theme
    const themeToggle = document.getElementById('theme-toggle');

    function checkTimeAndSetTheme() {
      const hour = new Date().getHours();
      // Night from 21:00 to 07:00
      const isNight = hour >= 21 || hour < 7;

      if (isNight) {
        document.body.classList.add('dark-theme');
        themeToggle.checked = true;
      } else {
        document.body.classList.remove('dark-theme');
        themeToggle.checked = false;
      }
    }

    themeToggle.addEventListener('change', () => {
      document.body.classList.toggle('dark-theme');
    });

    checkTimeAndSetTheme();